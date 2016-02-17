/*****************************************************************************/
/**
 *  @file   DataTag.cpp
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
#include "DataTag.h"
#include "XML.h"


namespace kvs_ext
{

namespace bdml
{

DataTag::DataTag() : Tag("data")
{
}

bool DataTag::read( const Node* parent )
{
    if ( !Tag::read( parent ) ) { return false; }

    if ( !scaleUnit.read( this->node() ) ) { return false; }

    Node* this_node = FindNode( this->node(), ComponentTag().name() );
    while ( this_node )
    {
        ComponentTag tag;
        tag.read( this_node );
        component.push_back( tag );
        this_node = this->node()->IterateChildren( tag.name(), this_node );
    }

    return true;
}

} // end of namespace bdml

} // end of namespace kvs_ext
