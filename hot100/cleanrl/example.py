"""
CleanRL DQN 简单示例
基于CleanRL的DQN算法实现概念演示
注：这是一个简化的示例，用于演示CleanRL的基本思想
"""

import gymnasium as gym
import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
import random
from collections import deque

class QNetwork(nn.Module):
    """Q网络"""
    def __init__(self, obs_space, action_space):
        super().__init__()
        self.network = nn.Sequential(
            nn.Linear(np.array(obs_space.shape).prod(), 120),
            nn.ReLU(),
            nn.Linear(120, 84),
            nn.ReLU(),
            nn.Linear(84, action_space.n),
        )

    def forward(self, x):
        return self.network(x)

def train_dqn():
    """训练DQN智能体"""
    env = gym.make("CartPole-v1")
    q_network = QNetwork(env.observation_space, env.action_space)
    optimizer = optim.Adam(q_network.parameters(), lr=2.5e-4)
    
    # 经验回放缓冲区
    replay_buffer = deque(maxlen=10000)
    epsilon = 1.0  # 探索率
    gamma = 0.99  # 折扣因子
    batch_size = 32
    
    # 训练循环
    for episode in range(100):
        obs, _ = env.reset()
        done = False
        total_reward = 0
        
        while not done:
            # Epsilon-greedy策略选择动作
            if random.random() < epsilon:
                action = env.action_space.sample()  # 探索
            else:
                with torch.no_grad():
                    q_values = q_network(torch.Tensor(obs))
                    action = torch.argmax(q_values).item()  # 利用
            
            # 执行动作
            next_obs, reward, terminated, truncated, _ = env.step(action)
            done = terminated or truncated
            total_reward += reward
            
            # 存储经验
            replay_buffer.append((obs, action, reward, next_obs, done))
            obs = next_obs
            
            # 经验回放学习
            if len(replay_buffer) >= batch_size:
                batch = random.sample(replay_buffer, batch_size)
                states, actions, rewards, next_states, dones = zip(*batch)
                
                states = torch.FloatTensor(states)
                actions = torch.LongTensor(actions)
                rewards = torch.FloatTensor(rewards)
                next_states = torch.FloatTensor(next_states)
                dones = torch.FloatTensor(dones)
                
                # 计算Q值和目标Q值
                q_values = q_network(states).gather(1, actions.unsqueeze(1)).squeeze()
                with torch.no_grad():
                    next_q_values = q_network(next_states).max(1)[0]
                    target_q_values = rewards + gamma * next_q_values * (1 - dones)
                
                # 更新网络
                loss = nn.MSELoss()(q_values, target_q_values)
                optimizer.zero_grad()
                loss.backward()
                optimizer.step()
        
        # 衰减探索率
        epsilon = max(0.01, epsilon * 0.995)
        print(f"Episode {episode}, Total Reward: {total_reward}, Epsilon: {epsilon:.3f}")
    
    env.close()

if __name__ == "__main__":
    train_dqn()
