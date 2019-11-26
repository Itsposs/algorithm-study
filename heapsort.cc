

void shiftdown(int index) {
	// flag 标志
	int min, flag = 0;
	// n 待调整的整数数量
	while (index * 2 <= n && flag == 0) {
		t = 2 * i;
		// array 待调整的数组
		if (array[i] > array[t])
			min = t;
		else
			min = i;
		if (i * 2 + 1 <= n) {
			if (array[i] > array[i * 2 + 1])
				min = i * 2 + 1;
		}

		if (i != min) {
			std::swap(i, min);
		}
		else
			flag = 1;
	} 
}


void shiftup(int index) {
	int flag = 0;
	// index = 1 到达根结点
	if (index == 1) return;

	while (index != 1; flag == 0) {
		if (array[index] < array[index / 2])
			std::swap(i, i / 2);
		else
			flag = 1;
		// 继续向上调整
		i = i / 2;
	}
}


void create() {
	int i = 0;
	for (i = n / 2; i >= 1; i--) {
		shiftdown(i);
	}
}

int deletemax() {
	int min = 0;
	min = array[1];
	array[1] = array[n];
	n--;
	shiftdown(1);
	return min;
}

void heapsort() {
	while (n > 1) {
		std::swap(1, n);
		n--;
		shiftdown(1);
	}
}


