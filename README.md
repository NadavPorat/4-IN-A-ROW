
## Welcome to my consul lab test environment

# Overview
This is a Vagrant setup that will download, install, and configure the lab, using vagrant and virtual box

- #### :electric_plug:Quickstart
Bring the vagrant instance up.
clon the repositories / download the consul-lab folder 
navigate to this folder (using the cd /your way/  command on terminal)

```
vagrant up

```

access consul ui Server at 172.20.20.10:8500 in your local browser
access consul ui Agent at 172.20.20.40:8500 in your local browser
access apache at 172.20.20.40:8080 in your local browser



- ### :notebook: The steps for bulding this project:
  1. lern vagrant
  2. lern consul
  3. lern apache2
  4. how to config Vm and set conul as a server
  5. how to activate consul ui
  6. how the define memory and cpu for VM
  7. Multi-Machine - how we define and congig them, use same data center
  8. how to change listen port of apache
  9. create health check

  *base alot on the official guide of HashiCorp

- ### :globe_with_meridians: Technicals
  - Written in rubi
  - base on virtual box ,vagrant and consul softwares

