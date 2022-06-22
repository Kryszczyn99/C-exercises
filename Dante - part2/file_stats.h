#ifndef WSK_DO_F
#define WSK_DO_F

enum file_state_t
{
  EXIST,
  NON_EXIST
};

struct file_stats_t
{
  char *filename;
  int size;
  enum file_state_t state;
};

struct file_stats_t *check_files(int N, ...);

#endif
