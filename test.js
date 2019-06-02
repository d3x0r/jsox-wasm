var JSOXwasm = require( "./jsox-w.js" );

JSOXwasm.onRuntimeInitialized =()=>{
	JSOXwasm._initJSOX();
    //console.log( "WASMTHing:", JSOXwasm, JSON.stringify( Object.keys( JSOXwasm), null, "\t" ) );
    
	console.log( "JSOX:", JSOXwasm.parse("[1,2,3]",null) );//Object.keys() );

	var start = Date.now();
        var n;
    	for( n = 0; n < 100000; n++ ){
        	JSOXwasm.parse( "[1,2,3,4,5,6,7,8,10]" );
        	JSOXwasm.parse( '"one simple string to parse..."' );
        }
        var end = Date.now();
        console.log( "%d in %d %d", n, end-start, n /(end-start));

	var start = Date.now();
        var n;
    	for( n = 0; n < 100000; n++ ){
        	JSON.parse( "[1,2,3,4,5,6,7,8,10]" );
        	JSON.parse( '"one simple string to parse..."' );
        }
        var end = Date.now();
        console.log( "%d in %d %d", n, end-start, n /(end-start));


}