/*****************************************************************************/
/**
 *  @file   ComponentTag.h
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
#include "MeasurementTag.h"
#include <string>


namespace kvs_ext
{

namespace bdml
{

struct ComponentTag : public Tag
{
    std::string componentID;
    std::string componentName;
    float time;
    std::string prevID;
    MeasurementTag measurement;

    ComponentTag();

    bool read( const Node* node );
};

} // end of namespace bdml

} // end of namespace kvs_ext
