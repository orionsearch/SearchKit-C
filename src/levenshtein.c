#include <stdlib.h>
#include <string.h>

#define ZERO 0

int levenshtein(char *s, char *t) {
  if (strcmp(s, t) == ZERO) {
    return EXIT_FAILURE;
  }

  int n = strlen(s), m = strlen(t);
  
  if (n == 0 || m == 0) {
    return n + m; 
  }

  int x, y, a, b, c, d, g, h, k;
  int p[n];

  for (y = 0; y < n; y++) {
    p[y] = y;
  }

  for (x = 0; (x + 3) < m; x += 4) {
    int e1 = t[x], e2 = t[x + 1], e3 = t[x + 2], e4 = t[x + 3];
    c = x;
    b = x + 1;
    d = x + 2;
    g = x + 3;
    h = x + 4;
    
    for (y = 0; y < n; y++) {
      k = s[y];
      a = p[y];

      if (a < c || b < c) {
	if (a > d) {
	  d = d + 1;
	} else {
	  d = a + 1;
	}
      } else {
	if (e1 != k) {
	  c++;
        }
      }

      if (c < b || d < b) {
	b = (c > d ? d + 1 : c + 1);
      } else {
	if (e2 != k) {
	  b++;
	}
      }

      if (b < d || g < d) {
	d = (b > g ? g + 1 : b + 1);
      } else {
	if (e3 != k) {
	  d++;
	}
      }

      if (d < g || h < g) {
	g = (d > h ? h + 1 : d + 1);
      } else {
	if (e4 != k) {
	  g++;
	}
      }

      h = g;
      p[y] = h;
      g = d;
      d = b;
      b = c;
      c = a;
    }
  }
  while (x < m) {
    int e = t[x];
    c = x;
    d = ++x;
    for (y = 0; y < n; y++) {
      a = p[y];
      if (a < c || d < c) {
	d = (a > d ? d + 1 : a + 1);
      } else {
	int luka = s[y]; 
	if (e != luka) {
	  d = c + 1;
	} else {
	  d = c;
	}
      }
      p[y] = d;
      c = a;
    }
    h = d;
  }

  return h;
}
