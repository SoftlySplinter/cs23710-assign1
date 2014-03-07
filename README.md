# CS23710 Assessed Assignment 2010-11 Relocating Aberystwyth Dairy Company

*This was an assignment which I completed in 2010.*

> David Price and Fred Long
> 
> November 9, 2010

## Introduction

PLEASE NOTE: We require that your programs are compliant with a recognised
version of ANSI 'C'.

Our “official environment” in which all your user programs must run, and in
which we will test them, is that provided by the Computer Science computers
wiked and minted.

The best way to access these machines is via the SunRay units in room B57. It is
also possible to access wiked and minted from other campus networked computers
running an X Window System such as that provided by Xming. You are likely to
have to quote their fully qualified DNS names as wiked.dcs.aber.ac.uk or
minted.dcs.aber.ac.uk from many locations.

You must use one of the following to develop and debug your program.

* NetBeans and the compilers and debuggers accessible from it;
* SunStudio and the compilers and debuggers accessible from it.

## Aberystwyth Dairy Company

### Company Operations

Imagine you are working for the the director of development of the Aberystwyth
Dairy Company. The company has been established for many years and delivers
products to an extensive set of villages and towns distributed widely across Mid
Wales. It makes all deliveries using its own vehicles. As the network of
retailers has grown, the company's vans now drive great distances to make some
deliveries.

While the size of the deliveries vary, they only ever carry the products for a
single retailer in each trip, the van then returning empty to Aberystwyth to
reload and set out again. Each delivery fills more than half of a delivery van
and so they simply cannot combine deliveries to more than one retailer.

Transport costs now make up a very substantial proportion of the company's
overall operating costs.

The company has decided to consider relocating its whole operation to a new
location elsewhere in Mid Wales. There is a small set of towns where the Welsh
Assembly is constructing new business parks.

### Your Role

You are the only software designer/developer that works for the company. You
have been allocated the task of designing and implementing an application
program to evaluate the financial implications associated with the possible move
to a new location. You have been told to **only** consider transport costs
associated with the deliveries to the retailers.

While you are working for the Aberystwyth Dairy Company, you have been told that
your program must be made more generic. The Welsh Assembly have agreed to
provide a "grant" to cover the cost of implementing the software application and
they need to be able to use it to help other companies plan potential
relocations too.

You are supplied with information about the number of deliveries made to each of
the retailers, the size of those deliveries and the town or village in which
each retailer is located.

You are also given the list of new industrial parks and their locations.

You are told you must construct your application program in two phases.

* For the first phase, you only consider distances between the potential new
  industrial parks and the retailers and the number of deliveries to each. You
  are told to ignore the size of the deliveries. 
  Your measure of overall “cost” must not be financial, but purely the total
  distance that the delivery vans would have to travel in a single week.
* For the second phase, you are asked to make your application more
  sophisticated and to also consider the size of the deliveries. Heavier
  deliveries use more fuel.
  For this phase, your measure of overall “cost” must be financial. You are
  given extra data about the financial cost of a delivery van travelling a mile,
  and how this varies depending on the load that is being carried.

## The Data Provided

For the purposes of this assignment, we assume that Mid Wales has only a limited
number of towns and villages and that these are linked by a small number of
roads.

We provide you with six types of data file.

1. The first file is the “company description file”. It contains six lines of
   information. The first line contains the name of the company. The second to
   sixth lines contain the names of the files whose contents is described below,
   in the order as given below.
2. The second file provides information that describes a geographical region and
   the locations within it. The first line contains the name of the region. This
   is then followed by a set of lines of information, one per location. On each
   line you are given an integer, being the allocated town or village code
   number, followed by the name of the town or village (which may include spaces
   or punctuation). The code numbers start from zero and no number is omitted.
3. The third data file contains lines of data, one per road which is suitable
   for use by the delivery vehicles. On each line you are given the code number
   of a village or town, followed by the code number of a second village or
   town, followed by a third integer; that integer being the length of the road
   in miles.
4. The fourth file contains a set of integers that are the code numbers of the
   towns or villages where the new industrial parks are located.
5. The fifth file contains information related to the number and size of
   deliveries made to retailers in the various towns and villages. Each line in
   the file contains data for a single retailer and consists of four items of
   information. On each line you are given an integer which is a retailer
   number, followed by the code number of the village or town where they are
   located, followed by a third integer; that integer being the number of
   deliveries that have each week, followed by a final integer which is the
   number of kilograms of goods in each delivery. The retailer numbers start
   from zero and no number is omitted.
6. The sixth file contains information about the running costs of the company's
   vans. There is a single line with two real numbers. The first number is the
   number of pence per mile that it costs to run the van when it is empty. The
   second number is the extra number of pence per mile it costs to run the van
   per kilogram of diary products being carried on board.

### Alternative Data Files

The data we provide must not be “hard coded” into your program in any way.

It should be possible for us to provide new data files and then use your program
to process the data purely by us providing the names of the new files.

Indeed, we may choose to deliberately have some extra data files, of exactly the
same format, which we choose to use when we evaluate your program, which quite
deliberately are NOT available to you during development!

While any files we would use would be of the same format to those described
above, we might have different numbers of towns and villages, we might introduce
vans that cost more or less to operate, we might alter the size and regularity
of deliveries and we might rename the company!

## Pre-compiled Program Code that we Supply

We are providing you with a pre-compiled version of a function that you are
required to use.

The function takes as input information representing the road connectivity of an
area and the start and end locations of a desired journey. Our function provides
as its return value the best (“shortest”) route between the start and end
locations.

The detailed definition of the interface to our function is provided as a well
commented C header file which is downloadable from the Blackboard course web
site.

Note: as you require the overall distances between locations, you will have to
process the best route that we return and calculate the distance of that route.

## Your Tasks

### Your First Task

You are required to locate the town or village with a new industrial park that
the company should relocate to.

Your selection criteria is that you wish to minimize the number of miles covered
by the company's deliver vehicles if they have to supply the current retailers
with the same number of deliveries as at the present time.

### Your Second Task

For this task, your selection criteria is that you wish to minimize the running
costs of the vehicles.

For this, you need to allow for the number of kilograms delivered to each
retailer. Heavier loads cost more pence per mile as noted earlier.

### Implementation Requirements

You are expected to make good use of the facilities of the C programming
language (1989) or C99 that are supported by our compilers.

Your program must make use of arrays and linked data structures at appropriate
places.

Your program must make good use of functions to modularise your code in a
sensible way.

### Comments and layout

We do of course expect students to sensibly comment their program, making sure
that all comments add real value and do not just, in essence, duplicate code.
The program should have good layout and must use meaningful names for variables,
structures and other identifiers.

### Choices you are free to make

You need to read in the data files and store the information within suitable
data structures, which you have designed, within your program.

Your program should use multiple functions, located in multiple files as you
choose.

As part of our assessment, we will evaluate the quality of the choices you have
made.

## Assessment Criteria

Bearing in mind that this project concerns software development, the most
appropriate “assessment criteria” are those in Appendix AA of the student
handbook, namely those for “Assessment Criteria for Development”.

This assignment is worth 50% of the total marks available for this module.

NOTE: Solutions which do not tackle the second task could potentially be awarded
a mark of up to 75% if they cannot be criticized in any manner and are
accompanied by all other materials as indicated below.

Solutions must also tackle the second task for marks of 76% or above.

## The Material You Must Submit

You MUST hand in a printed version of all sections of the code of your program.

You MUST hand in printout showing the results of attempting to compile your
program and any errors or warnings that are produced.

You MUST give in the printout of the output generated when running your program
when you have used information that matches our sample scenarios as input data.

You MUST hand in a short written document describing the design decisions you
made. This document must be brief and between two and four sides of A4 in
length. Include diagrams if you wish to help explain your design.

If you have used any minor pieces of code taken from elsewhere, or drawn
understanding from published books or web pages, you should include appropriate
references and a bibliography in your document.

Please make sure you fully understand the department's stance on plagiarism as
described in the current student handbook.

You MUST make available a machine readable version of your program on a CD or
DVD or on a “USB pendrive”. HOWEVER, please note that the item containing the
machine readable version of the program will NOT be returned to you but will be
retained by the Department.

You MUST put all the written material you hand in in a single folder and it MUST
be possible to read all sheets that you hand in without having to remove them
from the folder. In particular, you must not hand in loose sheets in a bag, or
put everything in a single plastic pocket of a folder. The “folder” does not
need to be a commercially made folder, indeed, we are happy to accept sheets
neatly stapled together as a “leaflet”.

The CD, DVD or USB pendrive MUST be attached to your written material in a
sensible manner so that on the one hand it will not get lost, but on the other
hand, it is easy for us to remove and use.

NOTE: This is an “individual” assignment and must be completed as a one person
effort by the student submitting the work.

You must attach, to the front of your submission, a completed and signed copy of
the departmental standard assignment cover sheet which includes a Declaration of
Originality.

## Submission Date

Your solution to this assignment must be handed in to the Computer Science
collection system between 9:15am and 10:45am on Friday 17th December 2010.

It is not acceptable to miss any lecture for the purposes of completing
assignment work, in terms of the department's monitoring of student attendance
and any actions that might be taken in respect of poor attendance.

## Feedback

It is our intention to provide you with individual feedback on your work by
approximately mid January, but we can't guarantee that this will be available
before you sit the exam for this module.

Thus, we attempt to provide an alternative form of feedback very early. Within
two or three days of the submission deadline, once we have checked all material
submitted, we plan to release a “sample solution” to the problem. Students will
then be able to compare their own work to that of our solution.

If students have struggled on any issues, they will be able to see how we have
tackled things.

We believe this is a very positive approach to providing rapid feedback.
