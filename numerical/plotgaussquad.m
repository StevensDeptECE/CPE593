s=.05;
x=[0:s:1];
y=[x.^3 0 0];
x=[x 1 0];
x2=[0:-s:-1];
y2=[x2.^3 0 0];
x2=[x2  -1 0];
close all
figure
fill(x,y,1);
axis([-1,1,-1,1]);
hold on
fill(x2,y2,1);

#2nd order points
x0=-1/sqrt(3)
plot([x0,x0], [0,-.5], 'r')
plot([-x0,-x0], [0,+.5], 'r')
plot(x0, x0^3,'o', 'MarkerSize', 12, 'markerfacecolor', 'red')
plot(-x0, -x0^3,'o', 'MarkerSize', 12, 'markerfacecolor', 'red')
saveas(gcf, 'gaussquad.pdf', 'pdf');
