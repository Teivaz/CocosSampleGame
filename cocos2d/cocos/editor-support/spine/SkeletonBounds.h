/******************************************************************************
 * Spine Runtime Software License - Version 1.1
 * 
 * Copyright (c) 2013, Esoteric Software
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms in whole or in part, with
 * or without modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. A Spine Essential, Professional, Enterprise, or Education License must
 *    be purchased from Esoteric Software and the license must remain valid:
 *    http://esotericsoftware.com/
 * 2. Redistributions of source code must retain this license, which is the
 *    above copyright notice, this declaration of conditions and the following
 *    disclaimer.
 * 3. Redistributions in binary form must reproduce this license, which is the
 *    above copyright notice, this declaration of conditions and the following
 *    disclaimer, in the documentation and/or other materials provided with the
 *    distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#ifndef SPINE_SKELETONBOUNDS_H_
#define SPINE_SKELETONBOUNDS_H_

#include <spine/BoundingBoxAttachment.h>
#include <spine/Skeleton.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	float* const vertices;
	int count;
	int capacity;
} spPolygon;

spPolygon* spPolygon_create (int capacity);
void spPolygon_dispose (spPolygon* self);

int/*bool*/spPolygon_containsPoint (spPolygon* polygon, float x, float y);
int/*bool*/spPolygon_intersectsSegment (spPolygon* polygon, float x1, float y1, float x2, float y2);

#ifdef SPINE_SHORT_NAMES
typedef spPolygon Polygon;
#define Polygon_create(...) spPolygon_create(__VA_ARGS__)
#define Polygon_dispose(...) spPolygon_dispose(__VA_ARGS__)
#define Polygon_containsPoint(...) spPolygon_containsPoint(__VA_ARGS__)
#define Polygon_intersectsSegment(...) spPolygon_intersectsSegment(__VA_ARGS__)
#endif

/**/

typedef struct {
	int count;
	spBoundingBoxAttachment** boundingBoxes;
	spPolygon** polygons;

	float minX, minY, maxX, maxY;
} spSkeletonBounds;

spSkeletonBounds* spSkeletonBounds_create ();
void spSkeletonBounds_dispose (spSkeletonBounds* self);
void spSkeletonBounds_update (spSkeletonBounds* self, spSkeleton* skeleton, int/*bool*/updateAabb);

/** Returns true if the axis aligned bounding box contains the point. */
int/*bool*/spSkeletonBounds_aabbContainsPoint (spSkeletonBounds* self, float x, float y);

/** Returns true if the axis aligned bounding box intersects the line segment. */
int/*bool*/spSkeletonBounds_aabbIntersectsSegment (spSkeletonBounds* self, float x1, float y1, float x2, float y2);

/** Returns true if the axis aligned bounding box intersects the axis aligned bounding box of the specified bounds. */
int/*bool*/spSkeletonBounds_aabbIntersectsSkeleton (spSkeletonBounds* self, spSkeletonBounds* bounds);

/** Returns the first bounding box attachment that contains the point, or null. When doing many checks, it is usually more
 * efficient to only call this method if spSkeletonBounds_aabbContainsPoint returns true. */
spBoundingBoxAttachment* spSkeletonBounds_containsPoint (spSkeletonBounds* self, float x, float y);

/** Returns the first bounding box attachment that contains the line segment, or null. When doing many checks, it is usually
 * more efficient to only call this method if spSkeletonBounds_aabbIntersectsSegment returns true. */
spBoundingBoxAttachment* spSkeletonBounds_intersectsSegment (spSkeletonBounds* self, float x1, float y1, float x2, float y2);

/** Returns the polygon for the specified bounding box, or null. */
spPolygon* spSkeletonBounds_getPolygon (spSkeletonBounds* self, spBoundingBoxAttachment* boundingBox);

#ifdef SPINE_SHORT_NAMES
typedef spSkeletonBounds SkeletonBounds;
#define SkeletonBounds_create(...) spSkeletonBounds_create(__VA_ARGS__)
#define SkeletonBounds_dispose(...) spSkeletonBounds_dispose(__VA_ARGS__)
#define SkeletonBounds_update(...) spSkeletonBounds_update(__VA_ARGS__)
#define SkeletonBounds_aabbContainsPoint(...) spSkeletonBounds_aabbContainsPoint(__VA_ARGS__)
#define SkeletonBounds_aabbIntersectsSegment(...) spSkeletonBounds_aabbIntersectsSegment(__VA_ARGS__)
#define SkeletonBounds_aabbIntersectsSkeleton(...) spSkeletonBounds_aabbIntersectsSkeleton(__VA_ARGS__)
#define SkeletonBounds_containsPoint(...) spSkeletonBounds_containsPoint(__VA_ARGS__)
#define SkeletonBounds_intersectsSegment(...) spSkeletonBounds_intersectsSegment(__VA_ARGS__)
#define SkeletonBounds_getPolygon(...) spSkeletonBounds_getPolygon(__VA_ARGS__)
#endif

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SKELETONBOUNDS_H_ */
