#include "traffic_light/traffic_light.h"

int main(void) {

	traffic_light_init();

	while(1) { traffic_light_run(); }

	return 0;
}
