function trapezoidal(a, b)
  h = b-a # 1 slice
  S_1 = 0.5*(f(a) + f(b))
  I_1 = h * S_1

  S_last = S_1;
  it = 2;
  n=1; # this is how many new points to add
  while n <= 8
    disp("");
    h = h / 2
    internalSum = 0;
    x = a + h;
    for i=1:n
      internalSum = internalSum + f(x);
      x = x + 2*h; # split every strip into 2
    end
    S_i = S_last + internalSum
    I_i = h * S_i
    S_last = S_i;
    n = n * 2
  end
end

function y = f(x)
  y = 2*x^3;
end
