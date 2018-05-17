seedsY;
seedsX;

x=x';
normX = x - min(x(:));
x = normX ./ max(normX(:));

%CALCULO DE PHI
phi=0;
for i=1:140
	if y(i) == 1
		phi = phi + 1;
	end
end
phi = (1/140)*phi

%CALCULO DE M0
num0=zeros(7,1);
den0=0;

for i=1:140
	if y(i) == 0
		num0 = num0 + x(:,i);
		den0 = den0 + 1;
	end
end
m0 = num0/den0

%CALCULO DE M1
num1=zeros(7,1);
den1=0;

for i=1:140
	if y(i) == 1
		num1 = num1 + x(:,i);
		den1 = den1 + 1;
	end
end
m1 = num1/den1

%CALCULO DE MATRIZ DE COVARIANZA
sum=zeros(7);
for i=1:140
	if y(i) == 0
		my = m0;
	else
		my = m1;
	end
	xn = x(:,i)-my;
	xt = (x(:,i)-my)';
	sum = sum + (xn * xt);
end
sigma = (1/140)*sum

pi = 3.1416;
for j=1:140
	xn = x(:,j)-m0;
	xt = (x(:,j)-m0)';
	e = exp((-1/2) * xt * inv(sigma) * xn);
	deter = sqrt(det(sigma));
	pxy0 = 1/(((2*pi)^(7/2)) * deter * e);
	xn = x(:,j)-m1;
	xt = (x(:,j)-m1)';
	e = exp((-1/2) * xt * inv(sigma) * xn);
	deter = sqrt(det(sigma));
	pxy1 = 1/(((2*pi)^(7/2)) * deter * e);
	if y(j) == 0
		px = 1 - phi;
	else
		px = phi;
	end
	pyx0 = pxy0 * px;
	pyx1 = pxy1 * px;
	if pyx0 < pyx1
		fprintf('El ejemplo %d se parece mas a la categoria 0\n', j);
	else
		fprintf('El ejemplo %d se parece mas a la categoria 1\n', j);
	end
end
	








