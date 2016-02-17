/*****************************************************************************/
/**
 *  @file   ComponentTag.cpp
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
#include "ComponentTag.h"
#include "XML.h"


namespace kvs_ext
{

namespace bdml
{

ComponentTag::ComponentTag() : Tag("component")
{
    componentID = "";
    componentName = "";
    time = 0.0f;
    prevID = "";
}

bool ComponentTag::read( const Node* node )
{
    Tag componentID_tag("componentID");
    if ( componentID_tag.read( node ) ) { componentID = NodeValue<std::string>( componentID_tag.node() ); }

    Tag componentName_tag("componentName");
    if ( componentName_tag.read( node ) ) { componentName = NodeValue<std::string>( componentName_tag.node() ); }

    Tag time_tag("time");
    if ( time_tag.read( node ) ) { time = NodeValue<float>( time_tag.node() ); }

    Tag prevID_tag("prevID");
    if ( prevID_tag.read( node ) ) { prevID = NodeValue<std::string>( prevID_tag.node() ); }

    if ( !measurement.read( node ) ) { return false; }

    return true;
}

} // end of namespace bdml

} // end of namespace kvs_ext
