/*****************************************************************************/
/**
 *  @file   LineTag.cpp
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
#include "LineTag.h"
#include "XML.h"


namespace kvs_ext
{

namespace bdml
{

LineTag::LineTag():
    Tag("line")
{
}

bool LineTag::read( const Node* parent )
{
    if ( !Tag::read( parent ) ) { return false; }

    Node* this_node = FindNode( this->node(), XYZSequenceTag().name() );
    while ( this_node )
    {
        XYZSequenceTag tag;
        tag.read( this_node );
        xyzSequence.push_back( tag );
        this_node = this->node()->IterateChildren( tag.name(), this_node );
    }

    return true;
}

} // end of namespace bdml

} // end of namespace kvs_ext
