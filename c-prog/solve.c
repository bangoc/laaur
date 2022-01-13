#include "cgen.h"

#include <stdio.h>
#include <string.h>

#define LEN 21
#define strequal(s1, s2) (strcmp(s1, s2) == 0)
typedef char id_str[21];

int n;
id_str *items, *pvs;

void parse_input(const char *fname) {
  FILE *inp = fopen(fname, "r");
  fscanf(inp, "%d", &n);
  items = malloc(n * sizeof(id_str));
  pvs = malloc(n * sizeof(id_str));
  for (int i = 0; i < n; ++i) {
    fscanf(inp, "%s%s", items[i], pvs[i]);
  }
  fclose(inp);
}

void free_input() {
  free(items);
  free(pvs);
}

void f1(const char *pid, const char *fname) {
  parse_input(fname);
  for (int i = 0; i < n; ++i) {
    if (strequal(pvs[i], pid)) {
      printf(" %s", items[i]);
    }
  }
  printf("\n");
  free_input();
}

gvec_t get_by_item(const char *iid) {
  gvec_t v = gvec_create(10, NULL);
  for (int i = 0; i < n; ++i) {
    if (strequal(items[i], iid)) {
      gvec_append(v, gtype_s(pvs[i]));
    }
  }
  gvec_qsort(v, gtype_qsort_s);
  return v;
}

void print_gvec(gvec_t v) {
  printf("Found: %ld\n", gvec_size(v));
  gvec_traverse(cur, v) {
    printf(" %s", cur->s);
  }
  printf("\n");
}

void f2(const char *iid, const char *fname) {
  parse_input(fname);
  gvec_t v = get_by_item(iid);
  print_gvec(v);
  gvec_free(v);
  free_input();
}

void f3(const char *fname) {
  parse_input(fname);
  hmap_t item_pvs = hmap_create(gtype_hash_s, gtype_cmp_s, NULL, NULL);
  for (int i = 0; i < n; ++i) {
    hmap_ires res = hmap_insert(item_pvs, gtype_s(items[i]), gtype_l(1));
    if (!res.inserted) {
      ++(res.value->l);
    }
  }
  long max = 0;
  const char *argmax;
  hmap_traverse(k, v, item_pvs) {
    if (max < v->l) {
      max = v->l;
      argmax = k->s;
    }
  }
  printf("%s\n", argmax);
  gvec_t v = get_by_item(argmax);
  print_gvec(v);
  gvec_free(v);
  hmap_free(item_pvs);
  free_input();
}

int main(int argc, char *argv[]) {
  if (strequal(argv[1], "f1")) {
    f1(argv[2], argv[3]);
  } else if (strequal(argv[1], "f2")) {
    f2(argv[2], argv[3]);
  } else if (strequal(argv[1], "f3")) {
    f3(argv[2]);
  } else {
    printf("Unknown command.\n");
  }
  return 0;
}