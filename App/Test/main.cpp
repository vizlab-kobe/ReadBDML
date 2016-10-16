#include <kvs/glut/Application>
#include <kvs/glut/Screen>
#include <ReadBDML/Lib/Importer.h>


int main( int argc, char** argv )
{
    kvs::glut::Application app( argc, argv );
    kvs::glut::Screen screen( &app );
    screen.show();

    ReadBDML::BDMLData bdml( argv[1] );
    bdml.print( std::cout );

//    const size_t cindex = 300;
//    screen.registerObject( ReadBDML::ImportLineObjectByComponent( bdml, 300 ) );

//    const size_t cindex = 300;
//    const size_t sindex = 0;
//    screen.registerObject( ReadBDML::ImportLineObjectBySequence( bdml, 300, 0 ) );

    const float time = 49;
    screen.registerObject( ReadBDML::ImportLineObjectByTime( bdml, time ) );

    return app.run();
}
