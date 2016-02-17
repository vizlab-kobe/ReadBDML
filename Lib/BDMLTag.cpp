/*****************************************************************************/
/**
 *  @file   BDMLTag.cpp
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
#include "BDMLTag.h"
#include "XML.h"


namespace kvs_ext
{

namespace bdml
{

BDMLTag::BDMLTag():
    Tag("bdml")
{
    version = 0.0f;
}

bool BDMLTag::read( const Node* parent )
{
    if ( !Tag::read( parent ) ) { return false; }

    const Element* element = ToElement( Tag::node() );
    if ( element )
    {
        version = AttributeValue<float>( element, "version" );
    }

    return true;
}

} // end of namespace bdml

} // end of namespace kvs_ext
