   set autoscale                        # scale axes automatically
      unset log                              # remove any log-scaling
      unset label                            # remove any previous labels
      set xtic auto                          # set xtics automatically
      set ytic auto                          # set ytics automatically
	  set tics font "Helvetica,10"
      set title "Bubble"
      set xlabel "Number of Hidden Layers"
      set ylabel "Accucarcy (%)"
      #set key 0.01,100
      #set label "Yield Point" at 0.003,260
      #set arrow from 0.0028,250 to 0.003,280
      set xr [0:100000]
      set yr [0:50]
      plot  "./data.txt" using 1:2 title 'best' with linespoints, 
      "./data.txt" using 1:3 title 'average' with linespoints, 
      "./data.txt" using 1:4 title 'worst' with linespoints
