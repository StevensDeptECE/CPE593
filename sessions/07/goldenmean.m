
function [a,b,x,y] = goldenmean (xmin,xmax, a, b, ymin, ymax)
  phi = (sqrt(5)+1)/2;
  s = (b-a) / phi;
  x = b - s;
  y = a + s;
  fill([a b b a], [ymin ymin f(b) f(a)], [0 0.6 0.3]);
  hold on
  step=0.5;
  t=xmin:step:xmax;
  plot (t, f(t), 'b-');
  plot (t, f(t), 'rs', 'MarkerFaceColor', 'red');

  plot([a,a], [ymin,ymax], 'k:');
  plot([b,b], [ymin,ymax], 'k:');
  
  plot([x,x], [ymin,ymax], 'b:');
  plot([y,y], [ymin,ymax], 'b:');
  axis([xmin, xmax, 0, ymax]);

  if f(x) > f(y)
    b = y;
    s = (b-a) / phi;    
    y = x;
    x = b-s;
  else
    a = x;
    s = (b-a) / phi;
    x = y;
    y = a + s;
  end
endfunction
