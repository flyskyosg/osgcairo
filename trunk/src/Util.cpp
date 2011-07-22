// -*-c++-*- osgCairo - Copyright (C) 2011 osgCairo Development Team
// $Id$

#include <osg/Math>
#include <osg/Notify>
#include <osgCairo/Util>

#include "cairocks.h"

namespace osgCairo {
namespace util {

bool writeToPNG(cairo_surface_t* surface, const std::string& path) {
#ifdef CAIRO_HAS_PNG_FUNCTIONS
	cairo_surface_write_to_png(surface, path.c_str());

	return true;
#else
	osg::notify(osg::WARN) << "Your version of Cairo does not support PNG writing!" << std::endl;

	return false;
#endif
}

bool roundedRectangle(
	cairo_t*       c,
	double         x,
	double         y,
	double         width,
	double         height,
	double         radius,
	const Corners& corners
) {
	return cairocks_rounded_rectangle(c, x, y, width, height, radius, corners.corners) != FALSE;
}

bool roundedRectangleApply(
	cairo_t*       c,
	double         x,
	double         y,
	double         width,
	double         height,
	double         radius,
	const Corners& corners
) {
	return cairocks_rounded_rectangle_apply(c, x, y, width, height, radius, corners.corners) != FALSE;
}

bool gaussianBlur(cairo_surface_t* surface, double radius, double deviation) {
	return cairocks_gaussian_blur(surface, radius, deviation) != FALSE;
}

bool mapPathOnto(cairo_t* c, cairo_path_t* path) {
	return cairocks_map_path_onto(c, path) != FALSE;
}

cairo_surface_t* createEmbossedSurface(
	cairo_surface_t* surface,
	double           azimuth,
	double           elevation,
	double           height,
	double           ambient,
	double           diffuse
) {
	return cairocks_emboss_create(surface, azimuth, elevation, height, ambient, diffuse);
}

cairo_surface_t* createDistanceField(
	cairo_surface_t* surface,
	int              scan_size,
	int              block_size
) {
	return cairocks_distance_field_create(surface, scan_size, block_size);
}

}
}

