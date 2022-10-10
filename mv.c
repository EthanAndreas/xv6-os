#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{

  if(argc != 3){
    printf(2, "Usage: mkdir files...\n");
    exit();
  }

  // link first argument to second argument
  if(link(argv[1], argv[2]) == -1){
    printf(2, "link: %s failed to create\n", argv[2]);
    exit();
  }

  // unlink first argument
  if(unlink(argv[1]) == -1){
    printf(2, "unlink: %s failed to delete\n", argv[1]);
    exit();
  }


  exit();
}
