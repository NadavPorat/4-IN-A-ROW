
# Welcome to my consul-lab test environment

## :desktop_computer: Overview

This is a Vagrant setup that will download, install, and configure the lab, using vagrant & virtual box

### :electric_plug: Quickstart

clon the repositories 

navigate to this folder via terminal

```
cd /path..
```

```
vagrant up
```


access ***consul ui Server*** at 172.20.20.10:8500 in your local browser.

access ***consul ui Agent*** at 172.20.20.40:8500 in your local browser.

access ***apache2*** at 172.20.20.40:8080 in your local browser.



## :notebook: The steps for building this project:

  1. Lern virtual box
  2. Lern vagrant
  3. Lern consul
  4. How to config VM and set consul as a server
  5. How to activate consul ui
  6. How the define memory and cpu for VM
  7. Multi-Machine - how we define and config, use same data center for both VM
  8. How to change listen port of apache
  9. Create and register health check 

  *base alot on the official guide of HashiCorp 
   - https://learn.hashicorp.com/consul
   
   - https://learn.hashicorp.com/tutorials/consul/deployment-guide

## :globe_with_meridians: Technicals

  - Written in rubi
  - base on virtual box ,vagrant and consul softwares


 <img width="1316" alt="consul nods" src="https://user-images.githubusercontent.com/71311119/125179126-f776e980-e1f3-11eb-9596-0f46bb6d9c98.png">
 
 <img width="1315" alt="health check" src="https://user-images.githubusercontent.com/71311119/125179163-681e0600-e1f4-11eb-9775-aaff3c793e9d.png">

<img width="1438" alt="stop apache" src="https://user-images.githubusercontent.com/71311119/125179167-710ed780-e1f4-11eb-890e-f424e3baf79a.png">

