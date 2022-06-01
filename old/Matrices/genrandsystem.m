function genrandsystem(n)
  A = round(rand(n) * n - n/2);
  B = round(rand(n,1)*n-n/2);
  x = A\B;

format long
disp(n);

disp(A);
disp('-------------------------------------');
disp(B);
disp('---------solution----------');
x = A\B
end
