<!-- Project Title -->
<h1 align="center">42 - Philosophers 🍽️</h1>

<!-- Project Description -->
<p align="center">
  This project simulates the classic "Dining Philosophers Problem." It involves a scenario where a group of philosophers sit around a circular table and attempt to eat under certain rules and constraints. The philosophers alternate between thinking and eating, attempting to avoid issues like deadlock and starvation. This project aims to provide experience in parallel programming, synchronization, and thread management.
</p>

<!-- Project Logo -->
<p align="center">
  <a target="blank"><img src="https://github.com/deryaxacar/42-Philosophers/blob/main/philosophers.png" height="150" width="150" /></a>
</p>

<!-- Project Goals -->
## Project Goals 🎯
<p>
  The project aims to help you understand synchronization between threads, the challenges of accessing shared resources, and solutions to such issues. You will explore different synchronization strategies and how they apply in concurrent environments.
</p>

<p>Main objectives of the project include:</p>
<ul>
  <li><strong>Understanding Synchronization Mechanisms 🔄:</strong> Analyze problems that may arise when philosophers share forks and synchronize their actions.</li>
  <li><strong>Preventing Deadlock and Starvation 🚫🍴:</strong> Understand what causes deadlock or starvation and explore techniques to prevent them.</li>
  <li><strong>Thread Management 👥:</strong> Ensure safe interaction of concurrently running threads in critical sections.</li>
</ul>

<!-- Project Explanation -->
## Project Explanation 📜
<p>
  The philosophers must follow specific rules to eat. Each philosopher must take the fork to their left and right to eat. Since there’s only one fork between each pair of philosophers, synchronization issues can occur, potentially preventing philosophers from eating or thinking.
</p>

<p>In this project, various synchronization strategies are implemented to avoid deadlock and starvation. Here are some of the mechanisms used:</p>
<ul>
  <li><strong>Locking 🔐:</strong> Uses mutexes to ensure a fork cannot be picked up by more than one thread at a time.</li>
  <li><strong>Semaphores 🚦:</strong> Manage the availability of forks and the order in which philosophers can pick them up.</li>
  <li><strong>Critical Section Management ⚠️:</strong> Protect access to shared resources by defining safe regions of execution.</li>
</ul>

<!-- Use Cases -->
## Use Cases 📝
<p>Use this project to experiment with different scenarios. Some recommended use cases include:</p>

### 1: Launching the Simulation with a Specific Number of Philosophers
Start the simulation by defining the number of philosophers. The more philosophers, the higher the synchronization challenge.

1. **Choose the Number of Philosophers:** Select how many philosophers will participate.
2. **Start the Simulation 🚀:** Run the program and observe the behavior.
3. **Analyze the Output 🔍:** Check how often each philosopher eats and thinks. Watch for deadlock or starvation.

### 2: Testing Locking Strategies
Test different locking strategies to reduce the risk of deadlock or starvation.

1. **Change the Locking Strategy 🔄:** Use different approaches (mutexes, semaphores, etc.).
2. **Re-run the Simulation 🔄:** Observe the behavior under each strategy.
3. **Compare Results ⚖️:** Evaluate which strategy performs better in preventing issues.

### 3: Experiment with Different Synchronization Mechanisms
Try various synchronization methods and analyze their effectiveness.

1. **Select a Mechanism 🧩:** Choose from mutexes, semaphores, or other techniques.
2. **Run and Observe 👀:** Watch how the simulation behaves under the selected mechanism.
3. **Find the Best Strategy 🥇:** Compare outcomes and determine the optimal approach.

## 4: Analyze Synchronization Issues and Propose Solutions
Investigate synchronization problems and apply appropriate fixes.

1. **Identify Issues 🛠️:** Watch for deadlock, starvation, or race conditions.
2. **Research Solutions 📚:** Look into solutions like resource hierarchy or priority mechanisms.
3. **Apply Fixes 🔧:** Implement and test changes, and analyze their impact.

<!-- Contribution -->
## Contributing 🤝
<p>To contribute to this project, follow these steps:</p>
<ol>
  <li><strong>Fork the Repository 🔄:</strong> Create a copy of the project under your GitHub account.</li>
  <li><strong>Make Changes 🛠️:</strong> Implement improvements in your local environment.</li>
  <li><strong>Submit a Pull Request 📩:</strong> Share your changes by creating a pull request and explaining your additions.</li>
</ol>

<!-- License -->
## License 📜
<p>This project is licensed under the <a href="LICENSE">MIT License</a>. See the license file for details.</p>

---

<p align="center">2025 This project was created by Derya ACAR.</p>
