#include "pipe_networking.h"


int main() {
  while (1){
  int to_client;
  int from_client;
    from_client = server_handshake( &to_client );
    while (1){
      char buffer[512] = {'\0'};
      int connection = read(from_client, buffer, sizeof(buffer));
      if (!connection){
        break;
      }
      buffer[strlen(buffer) - 1] = '\0';
      // changes all vowels into l, n, or z.
      for (int i = 0; i < strlen(buffer); i++){
        if (buffer[i] == 'a' | buffer[i] == 'i'){
          buffer[i] = 'l';
        }
        if (buffer[i] == 'e' | buffer[i] == 'u'){
          buffer[i] = 'n';
        }
        if (buffer[i] == 'u'){
          buffer[i] = 'z';
        }
      }
      write(to_client, buffer, strlen(buffer));
    }
  }
}
