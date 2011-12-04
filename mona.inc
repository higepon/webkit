# -DNDEBUG \

DEFINES = -DWTF_OS_MONA=1 \
          -DWTF_USE_CAIRO=1 \
          -DWTF_USE_CURL=1 \
          -DWTF_PLATFORM_MONA=1 \
          -DDISABLE_THREAD_CHECK \
          -DENABLE_PLUGIN_PACKAGE_SIMPLE_HASH\
          -DENABLE_NETSCAPE_PLUGIN_API=0\
          -DENABLE_3D_RENDERING=0 \
          -DENABLE_BLOB=0 \
          -DENABLE_CHANNEL_MESSAGING=0 \
          -DENABLE_CLIENT_BASED_GEOLOCATION=0 \
          -DENABLE_DATABASE=0 \
          -DENABLE_DATALIST=0 \
          -DENABLE_DETAILS=0 \
          -DENABLE_DOM_STORAGE=0 \
          -DENABLE_EVENTSOURCE=0 \
          -DENABLE_FILTERS=0 \
          -DENABLE_FTPDIR=0 \
          -DENABLE_FULLSCREEN_API=0 \
          -DENABLE_GEOLOCATION=0 \
          -DENABLE_INSPECTOR=0 \
          -DENABLE_ICONDATABASE=0 \
          -DENABLE_JAVASCRIPT_DEBUGGER=0 \
          -DENABLE_JIT=0 \
          -DENABLE_MATHML=0 \
          -DENABLE_METER_TAG=0 \
          -DENABLE_OFFLINE_WEB_APPLICATIONS=0 \
          -DENABLE_PROGRESS_TAG=0 \
          -DENABLE_REQUEST_ANIMATION_FRAME=0 \
          -DENABLE_SHARED_WORKERS=0 \
          -DENABLE_SINGLE_THREADED=1 \
          -DENABLE_SVG=0 \
          -DENABLE_SVG_ANIMATION=0 \
          -DENABLE_SVG_AS_IMAGE=0 \
          -DENABLE_SVG_DOM_OBJC_BINDINGS=0 \
          -DENABLE_SVG_FONTS=0 \
          -DENABLE_SVG_FOREIGN_OBJECT=0 \
          -DENABLE_SVG_USE=0 \
          -DENABLE_VIDEO=0 \
          -DENABLE_WEBGL=0 \
          -DENABLE_WEB_SOCKETS=0 \
          -DENABLE_WORKERS=0 \
          -DENABLE_XPATH=0 \
          -DENABLE_XSLT=0 \
          -DLOG_DISABLED=1 \
          -DUSE_SYSTEM_MALLOC \
          -DUSE_JSC=1\
          -DWEBKIT_VERSION_MIN_REQUIRED=WEBKIT_VERSION_LATEST \
          -DWTF_PLATFORM_MONA=1 \
          -D__i386__ \
          -DUSE_SYSTEM_MALLOC \
          -DENABLE_SINGLE_THREADED=1
ADDCXXFLAGS = -O3 \
-Wall \
-Wcast-qual \
-Wchar-subscripts \
-Wextra \
-Wformat-security \
-Wformat=2 \
-Winit-self \
-Wmissing-format-attribute \
-Wmissing-noreturn \
-Wno-c++0x-compat \
-Wno-sign-compare \
-Wno-switch \
-Wno-switch-enum \
-Wno-trigraphs \
-Wno-unused-parameter \
-Wpacked \
-Wpointer-arith \
-Wreturn-type \
-Wundef \
-Wwrite-strings \
-fno-exceptions \
-fno-rtti \
-fno-strict-aliasing \
-fvisibility-inlines-hidden \
-fvisibility=hidden \
-pipe \
$(DEFINES)

SOURCE_DIR  = ./Source
JSC_DIR     = $(SOURCE_DIR)/JavaScriptCore
WEBCORE_DIR = $(SOURCE_DIR)/WebCore


