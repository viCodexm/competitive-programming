struct Car {
	int speed;
	int weight;
};
const int speed_limit = 100;
const int weight_limit = 2000;

// code this
int count = 0;
for (const auto&[speed, weight] : cars)
	if (speed > speed_limit || weight > weight_limit)
		count++;

// instead of this
count = 0;
for (Car& car : cars)
	if (car.first > speed_limit || car.second > weight_limit)
		count++;
