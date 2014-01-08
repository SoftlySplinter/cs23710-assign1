/* 
 * File:   shortest.h
 * Author: dap
 *
 * Created on 09 November 2008, 12:00
 * Updated on 08 November 2010, 15:00
 */

#ifndef _SHORTEST_H
#define	_SHORTEST_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    /*
     * The following structure represents a usable road.
     * The from and to fields are the allocation code number of two locations.
     * All code numbers should be non-negative integers.
     * The length field is the length of that road.
     * The next field can be used to point to another structure of this type.
     */

    typedef struct rd {
        int from;
        int to;
        int length;
        struct rd * next;
    } road;

    /*
     * The following function attempts to locate the shortest route
     * between the two locations indicated by the parameters from and to.
     * The no_of_places parameter is used to specify the total number of locations
     * (that is, villages and towns) in the region.  Note: it is NOT the number
     * of roads in a region.
     * The final parameter, road_list, is a linked list of roads.  Each element
     * should match the structure provided above.   The order of the roads
     * in the road_list does not matter.
     *
     * The return value of the function is another linked list.
     * Assuming a route exists between the two locations, the linked
     * list returned contains the list of roads that go from the from location
     * to the to location in order.
     *
     * If the from and to locations are the same then a null pointer is returned.
     *
     * If a route does not exist between from and to then a null pointer
     * is returned.
     *
     * If the value given for from or to is negative, or is a value equal or larger than
     * no_of_places then a null pointer is returned.
     */
    
    road * shortest_route (int from, int to, int no_of_places, road * road_list);

#ifdef	__cplusplus
}
#endif

#endif	/* _SHORTEST_H */

