
#include "SDLA/renderer/window.h"
#include <SDLA/renderer/window.h>
#include "SDLA/core/types/color.h"
#include <SDLA/utils/errors.h>


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
#include <include/gpu/ganesh/gl/GrGLInterface.h>
#include <include/gpu/ganesh/gl/GrGLBackendSurface.h>



namespace SDLA {

  
PreviewRenderer::PreviewRenderer(){

  SDL::Init(SDL::INIT_VIDEO);
  SDL::GL_SetAttribute(SDL::GL_DOUBLEBUFFER, 1);
  SDL::GL_SetAttribute(SDL::GL_DEPTH_SIZE, 24);
  SDL::GL_SetAttribute(SDL::GL_STENCIL_SIZE, 8);


  window = SDL::CreateWindow(
    "SDLA Preview", 
    {0, 0},
    SDL::WINDOW_OPENGL | SDL::WINDOW_RESIZABLE
  );
  check_null_unlikely(window, "CreateWindow");


  SDL::GLContext gl_context(window);
  SDL::GL_MakeCurrent(window, gl_context);


  sk_sp<const GrGLInterface> interface = GrGLMakeNativeInterface();
  context = GrDirectContexts::MakeGL(interface);
  check_null_unlikely(context, "Context::MakeGL");

  // fetch window size
  SDL::GL_SwapWindow(window);
  SDL::PumpEvents();
  auto [width, height] = SDL::GetWindowSizeInPixels(window);
  
  surface = _create_sk_surface(width, height);
  check_null_unlikely(surface, "_create_sk_surface");
  canvas = surface->getCanvas();
  
  return;
}


void PreviewRenderer::clear(Color color) const {
  canvas->clear(color);
  return;
}

void PreviewRenderer::draw_path(const SkPath &path, const SkPaint &paint) const {
  canvas->drawPath(path, paint);
  return;
}

void PreviewRenderer::present() const {
  context->flush();
  SDL::GL_SwapWindow(window);
}
  
PreviewRenderer::~PreviewRenderer() {
  window.Destroy();  
}
  

sk_sp<SkSurface>  PreviewRenderer::_create_sk_surface(int w, int h){

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


void PreviewRenderer::idle() {
  bool running = true;
  while(running){
    while(auto ev = SDL::PollEvent()){
      if(ev->type == SDL::EVENT_QUIT) { running = false;}
    }
  }
  return;
}

}
  
