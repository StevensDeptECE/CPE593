constrainedPrimes(n) // O(n (log n)^2)
  count = 0
  for i = 2 to n
	if isPrime(i) //O(logn)
     	for (int k = 1; k <= n; k *=3) // O(log n )
        if k - 2 == i
     	    count++;
        end
	    end
	end
end


constrainedPrimes2(n) // O(m( log n)^2)
	for (int k = 1; k <= n; k *=3) // O(log n )
    if k - 2 == i	
    	if isPrime(i) //O(k logn)
  	    count++;
      end
    end
end

2.

constrainedPrimes(n) // O(n (log n)^3)
  count = 0
  for i = 2 to n
	if isPrime(i) //O(logn)
     	for (int k = 1; k <= n; k *=3) // O(log n )
				for (int j = 1; j <= k; j *= 2) //O(log n)
          if k - j == i
       	    count++;
            goto next;
          end
	    end
					next: // process next element
	end
end


constrainedPrimes2(n) // O(m(log n)^3)
	for (int k = 1; k <= n; k *=3) // O(log n )
		for (int j = 1; j <= k; j *= 2) //O(log n)
      if k - j == i
       	if isPrime(i) //O(k logn)
    	    count++;
        end
    end
end




			randomize numbers from 1 to 52

			sort the numbers

			for (int i= 1; i <=52; i++)
				a[i-1] = i;
