# Embedded_Scheduler
Co-operative scheduler for embedded projects

How to use :
1) Call increment_tick() of sch_main.c in a timer isr of periodicity 1mS.
2) Mention the function, that  need to be called in periodic way in task[] list of sch_config.c
3) Call scheduler_main() in infinite loop of main().

Ready to go...
