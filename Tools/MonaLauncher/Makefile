TARGET  = MLAUNCH
SOURCES = main.cpp

INSTDIR = $(BINDIR)/APPS/
INSTFILES = $(TARGET).map
SHAREDIR   = $(MONADIR)/share
ADDLINK    =  -lmonalibc-imp -lamonagui-imp --enable-auto-import -L ../../ --start-group -lwebcore -ljscore -licuin -licuuc -lmonalibc-imp -lamonagui-imp -lz-imp -lpng-imp -lcairo-imp -lxml2-imp -lcurl-imp --end-group
ADDLINKDEP = $(MONADIR)/lib/libamonagui-imp.a $(MONADIR)/lib/libmonalibc-imp.a ../../libwebcore.a
include $(SHAREDIR)/configs/monapi-exe.inc
include ../../mona.inc

CXXFLAGS += $(ADDCXXFLAGS)
WEBCORE_DIR=../../Source/WebCore
JSC_DIR=../../Source/JavaScriptCore
INCLUDE +=    -I$(WEBCORE_DIR) \
              -I$(WEBCORE_DIR)/accessibility \
              -I$(WEBCORE_DIR)/bindings \
              -I$(WEBCORE_DIR)/bindings/generic \
              -I$(WEBCORE_DIR)/bindings/js \
              -I$(WEBCORE_DIR)/bridge \
              -I$(WEBCORE_DIR)/bridge/jsc \
              -I$(WEBCORE_DIR)/css \
              -I$(WEBCORE_DIR)/dom \
              -I$(WEBCORE_DIR)/editing \
              -I$(WEBCORE_DIR)/fileapi \
              -I$(WEBCORE_DIR)/history \
              -I$(WEBCORE_DIR)/html \
              -I$(WEBCORE_DIR)/html/canvas \
              -I$(WEBCORE_DIR)/html/parser \
              -I$(WEBCORE_DIR)/html/shadow \
              -I$(WEBCORE_DIR)/inspector \
              -I$(WEBCORE_DIR)/loader \
              -I$(WEBCORE_DIR)/loader/appcache \
              -I$(WEBCORE_DIR)/loader/archive \
              -I$(WEBCORE_DIR)/loader/cache \
              -I$(WEBCORE_DIR)/loader/icon \
              -I$(WEBCORE_DIR)/notifications \
              -I$(WEBCORE_DIR)/page \
              -I$(WEBCORE_DIR)/page/animation \
              -I$(WEBCORE_DIR)/plugins \
              -I$(WEBCORE_DIR)/rendering \
              -I$(WEBCORE_DIR)/rendering/style \
              -I$(WEBCORE_DIR)/rendering/svg \
              -I$(WEBCORE_DIR)/storage \
              -I$(WEBCORE_DIR)/platform \
              -I$(WEBCORE_DIR)/platform/animation \
              -I$(WEBCORE_DIR)/platform/text \
              -I$(WEBCORE_DIR)/platform/text/transcoder \
              -I$(WEBCORE_DIR)/platform/graphics \
              -I$(WEBCORE_DIR)/platform/graphics/mona \
              -I$(WEBCORE_DIR)/platform/graphics/transforms \
              -I$(WEBCORE_DIR)/platform/network \
              -I$(WEBCORE_DIR)/platform/network/curl \
              -I$(WEBCORE_DIR)/svg \
              -I$(WEBCORE_DIR)/xml \
              -I$(WEBCORE_DIR)/xml/parser \
              -I$(WEBCORE_DIR)/workers \
              -I$(WEBCORE_DIR)/DerivedSources/WebCore \
              -I$(JSC_DIR) \
              -I$(JSC_DIR)/assembler \
              -I$(JSC_DIR)/API \
              -I$(JSC_DIR)/heap \
              -I$(JSC_DIR)/interpreter \
              -I$(JSC_DIR)/jit \
              -I$(JSC_DIR)/runtime \
              -I$(JSC_DIR)/wtf \
              -I $(MONADIR)/core/icu/icu/source/common  \
              -I $(MONADIR)/core/icu/icu/source/i18n/ \
              -I $(MONADIR)/include/cairo \
              -I ../../Source/WebKit/mona/WebCoreSupport/ \
              -I $(HOME)/mingw/include

-include dependencies

check-syntax:
	LANG=C $(CXX) -o nul -fsyntax-only $(CXXFLAGS) $(INCLUDE) -S ${CHK_SOURCES} && python $(MONADIR)/tool/cpplint.py ${CHK_SOURCES}
