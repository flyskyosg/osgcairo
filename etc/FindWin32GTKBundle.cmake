SET(WIN32_GTK_BUNDLE_DIR "" CACHE PATH "Location of the GTK+ Win32 bundle.")

FIND_PATH(CAIRO_INCLUDE_DIRS cairo.h ${WIN32_GTK_BUNDLE_DIR})

IF (WIN32)
	SET(LIBCAIRO "cairo.lib")
ELSE (WIN32)
	SET(LIBCAIRO "libcairo.so")
ENDIF (WIN32)

FIND_PATH(CAIRO_LIBRARY_DIRS ${LIBCAIRO} ${WIN32_GTK_BUNDLE_DIR})
