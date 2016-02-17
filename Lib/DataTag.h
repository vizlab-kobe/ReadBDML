/*****************************************************************************/
/**
 *  @file   DataTag.h
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
#include "ScaleUnitTag.h"
#include "ComponentTag.h"
#include <vector>


namespace kvs_ext
{

namespace bdml
{

struct DataTag : public Tag
{
    ScaleUnitTag scaleUnit;
    std::vector<ComponentTag> component;

    DataTag();

    bool read( const Node* parent );
};

} // end of namespace bdml

} // end of namespace kvs_ext
