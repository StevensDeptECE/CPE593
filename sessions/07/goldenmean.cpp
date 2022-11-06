goldenmean(f, a, b, tolerance){
	phi = (1 + sqrt(5))/2
	s = (b - a) / phi
	c = b - s
	d = a + s
	while(b - a < tolerance){
			
		if(f(c) > f(d)){
			b = d;
			d = c;
			s = (b - a)/ phi;
			c = b - s;
		}
		else{
			a = c;
			c = d;
			s = (b - a) / phi;
			d = a + s;
		}
	}
}