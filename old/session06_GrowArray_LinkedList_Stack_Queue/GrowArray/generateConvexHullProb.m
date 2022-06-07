function p = generateConvexHullProb(n, numBoxes)
  clf;
  p1 = genRandPoints(n, 3, -5);
  p2 = genRandPoints(n, -5, +1.5);
  p3 = genRandPoints(n,0,0);
  p = [p1;p2;p3];
  plot(p(:,1),p(:,2),'*');

  xmin = min(min(p(:,1)));
  xmax = max(max(p(:,1)));
  xstep = (xmax-xmin)/numBoxes;
  ymin = min(min(p(:,2)));
  ymax = max(max(p(:,2)));
  ystep = (ymax-ymin)/numBoxes;
  
  x=[];
  y=[];
  for xv = xmin:xstep:xmax
    x = [x xv xv nan xmin xmax nan];
  end
  for yv = ymin:ystep:ymax
    y = [y ymin ymax nan yv yv nan];
  end
  hold on
  plot(x,y);
end

function p = genRandPoints(n, dx,dy)
  p = rand(n,2);
  for i=1:20
	  p = p + rand(n,2);
  end
  p(:,1) = p(:,1) + dx;
  p(:,2) = p(:,2) + dy;
end


