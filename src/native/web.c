#include "web.h"

#include <objc/runtime.h>
#include <objc/message.h>
#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CoreGraphics.h>
#include <AppKit/AppKit.h>

enum NSBackingStoreType
{
	NSBackingStoreRetained,
	NSBackingStoreNonretained,
	NSBackingStoreBuffered
};

enum
{
  NSBorderlessWindowMask = 0,
  NSTitledWindowMask = 1,
  NSClosableWindowMask = 2,
  NSMiniaturizableWindowMask = 4,
  NSResizableWindowMask = 8,
  NSTexturedBackgroundWindowMask = 256,
  NSUnscaledWindowMask = 2048,
  NSUnifiedTitleAndToolbarWindowMask = 4096,
  NSIconWindowMask = 64,
  NSMiniWindowMask = 128
};

static id alloc(char *class_name)
{
	return objc_msgSend(
		objc_getClass(class_name),
		sel_registerName("alloc")
	);
}

static id init(id alloc)
{
	return objc_msgSend(
		alloc,
		sel_registerName("init")
	);
}

static id allocinit(char *class_name)
{
	return init(
		alloc(class_name)
	);
}

int tramp_webview_show(char *start_url)
{
	id autoreleasePool = allocinit("NSAutoreleasePool");
	id app = allocinit("NSApplication");

	struct CGRect rect = CGRectMake(0, 0, 640, 480);

	id window = objc_msgSend(
		alloc("NSWindow"),
		sel_registerName("initWithContentRect:"),
		rect,
		NSTitledWindowMask | NSMiniaturizableWindowMask,
		NSBackingStoreBuffered,
		NO
	);

	objc_msgSend(window, sel_registerName("setTitle:"), "New Window");
	objc_msgSend(window, sel_registerName("center"));
	objc_msgSend(window, sel_registerName("makeKeyAndOrderFront:"), NULL);

	objc_msgSend(app, sel_registerName("run"));
    objc_msgSend(autoreleasePool, sel_registerName("drain"));

	return 42;
}
