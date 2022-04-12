#include "httpd.h"

int main(int c, char** v)
{
    serve_forever("12913");
    return 0;
}

void route()
{
    ROUTE_START()

    ROUTE_GET("/")
    {
        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("<h1>Hello! You are using</h1> <p style=\"color: blue;\">%s</p>", request_header("User-Agent"));
		printf("<br><a href=\"/detail\">detail</a>.");
    }

    ROUTE_POST("/")
    {
        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("Wow, seems that you POSTed %d bytes. \r\n", payload_size);
        printf("Fetch the data using `payload` variable.");
		
    }
	
	ROUTE_GET("/detail")
	{
		printf("HTTP/1.1 200 OK\r\n\r\n");
		printf("<h1>Example web site.</h1>");
		printf("<p>This is detail page.<br>Current web site from web server of the fork nginx.</p>");
	}
  
    ROUTE_END()
}
