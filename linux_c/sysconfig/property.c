#include <sys/system_properties.h> //android中使用

int main(){
	char value1[PROP_VALUE_MAX];
	if(0 != __system_property_get("ro.product.modle", value1)){
		printf("ro.product.modle = %s\n", value1);
	}

	return 0;
}>
