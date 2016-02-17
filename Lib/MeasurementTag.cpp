/*****************************************************************************/
/**
 *  @file   MeasurementTag.cpp
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
#include "MeasurementTag.h"
#include "XML.h"


namespace kvs_ext
{

namespace bdml
{

MeasurementTag::MeasurementTag():
    Tag("measurement")
{
    objectRef = "";
}

bool MeasurementTag::read( const Node* parent )
{
    if ( !Tag::read( parent ) ) { return false; }

    Tag objectRef_tag("objectRef");
    if ( objectRef_tag.read( this->node() ) ) { objectRef = NodeValue<std::string>( objectRef_tag.node() ); }

    if ( !line.read( this->node() ) ) { return false; }

    return true;
}

} // end of namespace bdml

} // end of namespace kvs_ext
