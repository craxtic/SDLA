/*     _          _
 *    / \   __  _(_)_ __ ___
 *   / _ \  \ \/ / | '_ ` _ \
 *  / ___ \  >  <| | | | | | |
 * /_/   \_\/_/\_\_|_| |_| |_|
 *
 * Copyright (c) 2026 The Axim Team
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org.
 */


#include <SDL3pp/SDL3pp_events.h>
#include <SDL3pp/SDL3pp_pixels.h>
#include <SDL3pp/SDL3pp_init.h>
#include <SDL3pp/SDL3pp_video.h>

#include <include/core/SkColor.h>
#include <include/core/SkColorSpace.h>
#include <include/core/SkSurface.h>
#include <include/core/SkCanvas.h>
#include <include/gpu/ganesh/GrDirectContext.h>
#include <include/gpu/ganesh/GrBackendSurface.h>
#include <include/gpu/ganesh/SkSurfaceGanesh.h>
#include <include/gpu/ganesh/gl/GrGLDirectContext.h>
#include <include/gpu/ganesh/gl/GrGLBackendSurface.h>
#include <include/gpu/ganesh/GrDirectContext.h>
#include <include/gpu/ganesh/gl/GrGLDirectContext.h>
#include <include/gpu/ganesh/gl/GrGLInterface.h>


#include <axim/drivers/window.h>
#include <axim/core/types/color.h>
#include <axim/utils/errors.h>

// #include <iostream>

namespace axm {

  
PreviewDriver::PreviewDriver(){

  SDL::Init(SDL::INIT_VIDEO);
  SDL::GL_SetAttribute(SDL::GL_DOUBLEBUFFER, 1);
  SDL::GL_SetAttribute(SDL::GL_DEPTH_SIZE, 24);
  SDL::GL_SetAttribute(SDL::GL_STENCIL_SIZE, 8);


  window = SDL::CreateWindow(
    "axim Preview", 
    {0, 0},
    SDL::WINDOW_OPENGL | SDL::WINDOW_RESIZABLE
  );
  check_null_unlikely(window, "CreateWindow");

  this->gl_context = SDL::GL_CreateContext(this->window);
  this->make_current();

  sk_sp<const GrGLInterface> interface = GrGLMakeNativeInterface();
  this->context = GrDirectContexts::MakeGL(interface);
  check_null_unlikely(context, "Context::MakeGL");


  return;
}

void PreviewDriver::make_current() {

  SDL::GL_MakeCurrent(this->window, this->gl_context);  
};



SkCanvas *PreviewDriver::get_canvas(){
  SDL::GL_SwapWindow(window);
  SDL::PumpEvents();
  auto [width, height] = SDL::GetWindowSizeInPixels(window);
  
  this->surface = _create_sk_surface(width, height);
  check_null_unlikely(surface, "_create_sk_surface");
  return this->surface->getCanvas();
}

void PreviewDriver::present() const {
  this->context->flush();
  SDL::GL_SwapWindow(window);
}
  
PreviewDriver::~PreviewDriver() {
  if (surface) surface->unref();
  context->unref();
  gl_context.Destroy();
  window.Destroy();  
}
  
sk_sp<SkSurface>  PreviewDriver::_create_sk_surface(int w, int h){

  GrGLFramebufferInfo gl_info = {0, 0x8058};
  GrBackendRenderTarget backend_rt = GrBackendRenderTargets::MakeGL(w, h, 0, 8, gl_info);


  // SkColorSpace color_space;
  SkSurfaceProps props(0, kUnknown_SkPixelGeometry);
  sk_sp<SkSurface> surface = SkSurfaces::WrapBackendRenderTarget(
    context.get(),
    backend_rt,
    kBottomLeft_GrSurfaceOrigin,
    kRGBA_8888_SkColorType,
    nullptr,
    &props
  );
  return surface;
}


/// TODO: handle the event with a proper window id
void PreviewDriver::idle() const {
  bool running = true;
  while(running){
    while(auto ev = SDL::PollEvent()){
      if(ev->type == SDL::EVENT_QUIT) { running = false;}
    }
  }
  return;
}

}
  
