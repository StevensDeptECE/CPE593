close all
xy = rand(1000,2);
plot(xy(:,1), xy(:,2), '.')
hold on
lines=[1:7] ./ 8;
for x=lines
  plot([x,x], [0,1]);
  plot([0,1], [x,x]);
end
