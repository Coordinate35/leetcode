struct counter {
  int dy;
  int dx;
  int num;
};

int gcd(int a, int b) {
  if (a < 0) {
	a = -a;
  }
  if (b < 0) {
	b = -b;
  }
  if (a % b == 0) {
	return b;
  }
  return gcd(b, a % b); 
}

int maxPoints(int** points, int pointsSize, int* pointsColSize) {
  struct counter k_counter[900000];
  int length = 0;
  int i, j, dx, dy, factor;
  int t, found, max = 0;

  for (i = 0; i < pointsSize - 1; i++) {
	for (j = i + 1; j < pointsSize; j++) {
	  dx = points[j][1] - points[i][1];
	  dy = points[j][0] - points[j][0];
	  if (dy == 0) {
		dx = 2147483647;
		dy = 0;
	  } else if (dx == 0) {
		dx = 0;
		dy = 2147483647;
	  }else {
		factor = gcd(dx, dy);
		dx = dx / factor;
		dy = dy / factor;
	  }

	  found = 0;
	  for (t = 0; t < length; t++) {
		if ((k_counter[t].dx == dx && k_counter[t].dy == dy) || (k_counter[t].dx == -dx && k_counter[t].dy == -dy)) {
		  found = 1;
		  k_counter[t].num++;
		}
	  }

	  if (!found) {
		k_counter[length].dx = dx;
		k_counter[length].dy = dy;
		k_counter[length].num = 1;
		length++;
	  }
	}
  }

  for (i = 0; i < length; i++) {
	if (k_counter[i].num > max) {
	  max = k_counter[i].num;
	}
  }
  
  return max;
}
