from collections import deque
from typing import List

class Solution:
    def maximumInvitations(self, favorites: List[int]) -> int:
        # Helper function to calculate the maximum distance from a given starting person
        def bfs(start_person: int, visited_people: set, reversed_graph: List[List[int]]) -> int:
            queue = deque([(start_person, 0)])  # Queue stores each person with their current distance
            max_distance = 0
            while queue:
                current_person, current_distance = queue.popleft()
                for admirer in reversed_graph[current_person]:  # Explore each admirer (neighbor)
                    if admirer in visited_people:
                        continue  # Skip if we've already visited this person
                    visited_people.add(admirer)
                    queue.append((admirer, current_distance + 1))
                    max_distance = max(max_distance, current_distance + 1)
            return max_distance

        num_people = len(favorites)  # Total number of people
        reversed_graph = [[] for _ in range(num_people)]  # Create an empty graph

        # Build the reversed graph where each person points to those who admire them
        for person in range(num_people):
            reversed_graph[favorites[person]].append(person)

        longest_cycle_length = 0  # To track the longest cycle length
        two_person_cycle_invitations = 0  # Invitations for 2-person cycles
        visited = [False] * num_people  # To track if we've visited a person

        # Find all cycles in the graph
        for person in range(num_people):
            if not visited[person]:  # If the person has not been visited yet

                # Dictionary to track people we've seen and their distances from the start
                visited_people = {}
                current_person = person
                distance = 0
                while True:
                    if visited[current_person]:
                        break  # Break the loop if we've already visited this person
                    visited[current_person] = True
                    visited_people[current_person] = distance
                    distance += 1
                    next_person = favorites[current_person]

                    # If we detect a cycle
                    if next_person in visited_people:
                        cycle_length = distance - visited_people[next_person]
                        longest_cycle_length = max(longest_cycle_length, cycle_length)

                        # Special handling for 2-person cycles (mutual admiration)
                        if cycle_length == 2:
                            visited_people_in_cycle = {current_person, next_person}
                            two_person_cycle_invitations += (
                                2  # Both people in the cycle can invite each other
                                + bfs(next_person, visited_people_in_cycle, reversed_graph)
                                + bfs(current_person, visited_people_in_cycle, reversed_graph)
                            )
                        break
                    current_person = next_person  # Move to the next person in the cycle

        # Return the maximum of the longest cycle or the total invitations for 2-person cycles
        return max(longest_cycle_length, two_person_cycle_invitations)
