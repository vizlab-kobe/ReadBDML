/*****************************************************************************/
/**
 *  @file   ScaleUnitTag.cpp
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
#include "ScaleUnitTag.h"
#include "XML.h"


namespace kvs_ext
{

namespace bdml
{

ScaleUnitTag::ScaleUnitTag() : Tag("scaleUnit")
{
    xScale = 0.0f;
    yScale = 0.0f;
    zScale = 0.0f;
    xyzUnit = "";
    tScale = 0.0f;
    tUnit = "";
}

bool ScaleUnitTag::read( const Node* parent )
{
    if ( !Tag::read( parent ) ) { return false; }

    Tag xScale_tag("xScale");
    if ( xScale_tag.read( this->node() ) ) { xScale = NodeValue<float>( xScale_tag.node() ); }

    Tag yScale_tag("yScale");
    if ( yScale_tag.read( this->node() ) ) { yScale = NodeValue<float>( yScale_tag.node() ); }

    Tag zScale_tag("zScale");
    if ( zScale_tag.read( this->node() ) ) { zScale = NodeValue<float>( zScale_tag.node() ); }

    Tag xyzUnit_tag("xyzUnit");
    if ( xyzUnit_tag.read( this->node() ) ) { xyzUnit = NodeValue<std::string>( xyzUnit_tag.node() ); }

    Tag tScale_tag("tScale");
    if ( tScale_tag.read( this->node() ) ) { tScale = NodeValue<float>( tScale_tag.node() ); }

    Tag tUnit_tag("tUnit");
    if ( tUnit_tag.read( this->node() ) ) { tUnit = NodeValue<std::string>( tUnit_tag.node() ); }

    return true;
}

} // end of namespace bdml

} // end of namespace kvs_ext
