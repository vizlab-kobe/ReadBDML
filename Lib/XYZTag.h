/*****************************************************************************/
/**
 *  @file   XYZTag.h
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


namespace ReadBDML
{

namespace bdml
{

/*===========================================================================*/
/**
 *  @brief  XYZ tag class.
 */
/*===========================================================================*/
struct XYZTag : public Tag
{
    float x; ///< x coordinate value
    float y; ///< y coordinate value
    float z; ///< z coordinate value

    XYZTag();

    bool read( const Node* node );
};

} // end of namespace bdml

} // end of namespace ReadBDML
