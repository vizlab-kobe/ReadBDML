/*****************************************************************************/
/**
 *  @file   BDMLData.cpp
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
#include "BDMLData.h"
#include "XML.h"


namespace kvs_ext
{

BDMLData::BDMLData( const std::string& filename )
{
    this->read( filename );
}

bool BDMLData::read( const std::string& filename )
{
    kvs::XMLDocument document;
    if ( !document.read( filename ) )
    {
        kvsMessageError( "%s", document.ErrorDesc().c_str() );
        return false;
    }

    if ( !m_bdml.read( &document ) )
    {
        kvsMessageError( "Cannot read <%s>.", m_bdml.name().c_str() );
        return false;
    }

    if ( !info.read( m_bdml.node() ) )
    {
        kvsMessageError( "Cannot read <%s>.", info.name().c_str() );
        return false;
    }

    if ( !data.read( m_bdml.node() ) )
    {
        kvsMessageError( "Cannot read <%s>.", data.name().c_str() );
        return false;
    }

    return true;
}

} // end of namespace kvs_ext
