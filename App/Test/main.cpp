#include <kvs/glut/Application>
#include <kvs/glut/Screen>
#include <kvs/LineObject>
#include <kvs/PointObject>
#include <kvs/LineRenderer>
#include <ReadBDML/Lib/Importer.h>


int main( int argc, char** argv )
{
    kvs::glut::Application app( argc, argv );
    kvs::glut::Screen screen( &app );
    screen.show();

    ReadBDML::BDMLData bdml( argv[1] );
    bdml.print( std::cout );

//    screen.registerObject( ReadBDML::ImportLineObjectByComponent( bdml, 300 ) );
//    screen.registerObject( ReadBDML::ImportLineObjectBySequence( bdml, 300, 0 ) );
    screen.registerObject( ReadBDML::ImportLineObjectByTime( bdml, 49 ) );

    return app.run();
}
