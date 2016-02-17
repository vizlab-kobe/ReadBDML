/*****************************************************************************/
/**
 *  @file   MeasurementTag.h
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
#include "LineTag.h"
#include <string>


namespace kvs_ext
{

namespace bdml
{

struct MeasurementTag : public Tag
{
    std::string objectRef;
    LineTag line;

    MeasurementTag();

    bool read( const Node* parent );
};

} // end of namespace bdml

} // end of namespace kvs_ext
