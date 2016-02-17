/*****************************************************************************/
/**
 *  @file   ScaleUnitTag.h
 *  @author Naohisa Sakamoto
 */
/*----------------------------------------------------------------------------
 *
 *  Copyright (c) Visualization Laboratory, Kyoto University.
 *  All rights reserved.
 *  See http://www.viz.media.kyoto-u.ac.jp/kvs/copyright/ for details.
 *
 *  $Id$
 */
/*****************************************************************************/
#pragma once

#include "Tag.h"
#include <string>


namespace kvs_ext
{

namespace bdml
{

struct ScaleUnitTag : public Tag
{
    float xScale;
    float yScale;
    float zScale;
    std::string xyzUnit;
    float tScale;
    std::string tUnit;

    ScaleUnitTag();

    bool read( const Node* parent );
};

} // end of namespace bdml

} // end of namespace kvs_ext
