/*****************************************************************************/
/**
 *  @file   XYZSequenceTag.h
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
#include <kvs/ValueArray>


namespace kvs_ext
{

namespace bdml
{

struct XYZSequenceTag : public Tag
{
    kvs::ValueArray<float> xyz;

    XYZSequenceTag();

    bool read( const Node* node );
};

} // end of namespace bdml

} // end of namespace kvs_ext
