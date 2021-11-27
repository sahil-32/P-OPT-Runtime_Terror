We have uploaded the complete updated ChampSim folder on Google drive along with our results.
We have included our application (app1.cpp) on which we have performed the simulation.

To run the simulation, we first need to compile the app1.cpp and then generate it's trace while pipeing the output to a file (graph_info.txt) here.
command :- pin -t obj-intel64/champsim_tracer.so -o ../../traces/app1.trace -- ./app1.out > graph_info.txt
followed by xz -v * in traces directory.
It contains the virtual address of src array and the graph structure as offset and neighbours (na) array.

We will need all this information in our popt algorithm so we manually copy all this data to base_replacement.cc file where 
we have implemented popt.

Now we can simply run the simulations by changing the llc_replacement policy from using lru_victim() to popt_victim() function in llc_replacement.cc and lru.llc_repl.
Then we can build using ./build_champsim.sh bimodal no no no no lru 1
followed by running
command :- /run_champsim.sh bimodal-no-no-no-no-lru-1core 0 100 app1.trace.xz
Then you can find the results under results_100M/ folder.

Modified Files:
ooo_cpu.cc (in src folder)
base_replacement.cc  (in replacement folder)
champsim_tracer.cpp (in tracer folder)
cache.h (in inc folder)
llc_replacement.cc  and lru.llc_repl (in replacement folder to change the policy)


