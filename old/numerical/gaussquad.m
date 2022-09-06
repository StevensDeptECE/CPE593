function gaussquad()
  g2 = gauss2(0,2)
  g3 = gauss3(0,2)
end

function est = gauss2(a,b)
  mid = (a+b)/2;
  h = (b-a)/2
  x0 = mid - h/sqrt(3)
  x1 = mid + h/sqrt(3)
  
  est = f(x0) + f(x1); # weights are 1.0 for Gauss 2nd order
end


function est = gauss3(a,b)
  mid = (a+b)/2;
  h = (b-a)/2
  x0 = mid;
  x1 = mid - h*sqrt(3/5)
  x2 = mid + h*sqrt(3/5)
  
  est = 8/9*f(x0) + 5/9*(f(x1)+f(x2)); # weights are 1.0 for Gauss 2nd order
end

function y = f(x)
  #y = 4*x^3; # 16 - 0 = 16
	#y = 5*x^4;
  #y = 6*x^5;
  #y = 7*x^6;
  y=exp(2*x);
end
				#  x^5 = 32
				#  x^6 = 64 (gauss3 is perfect)
				#  exp(2x) = 1/2*exp(2x)

