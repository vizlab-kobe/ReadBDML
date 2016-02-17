/*****************************************************************************/
/**
 *  @file   XYZSequenceTag.cpp
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
#include "XYZSequenceTag.h"
#include "XML.h"
#include "XYZTag.h"
#include <vector>


namespace kvs_ext
{

namespace bdml
{

XYZSequenceTag::XYZSequenceTag():
    Tag("xyzSequence")
{
}

bool XYZSequenceTag::read( const Node* node )
{
    std::vector<float> data;

    XYZTag tag;
    Node* this_node = FindNode( node, tag.name() );
    while ( this_node )
    {
        tag.read( this_node );
        data.push_back( tag.x );
        data.push_back( tag.y );
        data.push_back( tag.z );
        this_node = this->node()->IterateChildren( tag.name(), this_node );
    }

    xyz = kvs::ValueArray<float>( data );

    return true;
}

} // end of namespace bdml

} // end of namespace kvs_ext
