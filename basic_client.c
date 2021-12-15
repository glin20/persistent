#include "pipe_networking.h"


int main() {
  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );
  while (1){
    printf("Input: ");
    char buffer[512];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = '\0';
    write(to_server, buffer, strlen(buffer));
    read(from_server, buffer, sizeof(buffer));
    printf("%s\n", buffer);
  }
}
